#ifndef FORMEXERCISES_H
#define FORMEXERCISES_H

#include <QAbstractItemModel>
#include <QItemSelection>
#include <QWidget>

namespace Ui {
class FormExercises;
}

#include "exercise.h"
#include "formbase.h"

class FormExercises : public QWidget, public FormBase {
    Q_OBJECT

   public:
    explicit FormExercises(QWidget* parent = 0);
    void BeforeChange(std::shared_ptr<UIStateData> state_data) override;
    void AfterUndo(std::shared_ptr<UIStateData> state_data) override;
    QAbstractItemModel* createModel();
    ~FormExercises();

   private slots:
    void OnSelectionChanged(const QItemSelection& selection);
    void on__ok_clicked();

    void on__open_clicked();

   private:
    Ui::FormExercises* ui;
    std::shared_ptr<Exercise> _exercise;
    bool OpenProject(QString& file);
};

#endif  // FORMEXERCISES_H
