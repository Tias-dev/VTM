#ifndef UISTATENEWPROJECT_H
#define UISTATENEWPROJECT_H

#include <QErrorMessage>
#include <QMessageBox>

#include "VMTJsonSerializer.h"
#include "VMTProjectSaver.h"
#include "formnewproject.h"
#include "uistatestub.h"

class StateController;
class UIStateNewProjectData;

class UIStateNewProject : public UIStateStub<FormNewProject> {
   protected:
    UIStateNewProject(StateController* parent)
        : UIStateStub<FormNewProject>(parent) {
        parent->EnableExercise(false);
        parent->EnableNewMachine(false);
        parent->EnableOpenMachine(false);
        parent->EnableSave(true);
        parent->EnableExport(false);
        parent->EnablePlantUmlExport(false);
        parent->EnableRun(false);
        parent->EnableConfigure(false);
        parent->Enable4thExport(false);

        parent->EnableDebugBack(false);
        parent->EnableDebugOver(false);
        parent->EnableDebugPause(false);
        parent->EnableDebugRun(false);
        parent->EnableDebugStep(false);
        parent->EnableDebugStop(false);

        parent->EnableOk(false);
        parent->EnableCancel(false);

        parent->EnableZoom(false);
    }

    void Action(const QString& name) override {
        parent->Update();
        if (name == QString("button_save")) {
            if (VMTProjectSaver::SaveProject(&VMTProject::GetInstance())) {
                QMessageBox box;
                box.setText("Project saved");
                box.exec();
            } else {
                QErrorMessage error;
                error.showMessage("Can't save project :(");
                error.exec();
            }
        }
    }

    friend UIStateNewProjectData;

   public:
};

class UIStateNewProjectData : public UIStateData {
   public:
    std::shared_ptr<UIState> ConstructNewState(
        StateController* controller) override {
        return std::shared_ptr<UIStateNewProject>(
            new UIStateNewProject(controller));
    }
    std::shared_ptr<UIState> ConstructUndoState(
        StateController* controller) override {
        return std::shared_ptr<UIStateNewProject>(
            new UIStateNewProject(controller));
    }

    bool IsNeedWarning() override { return true; }

    QString GetName() override { return name; }

    void SetName(QString name) override { this->name = name; }

    QString name = "New machine";
};

#endif  // UISTATENEWPROJECT_H
