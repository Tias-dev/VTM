#include "ui.h"

#include <QMessageBox>

#include "VMTProjectSaver.h"

namespace utils::ui {
QChar escapeChar(QChar c) {
    if (c == QChar(' ')) {
        return QChar(L'λ');
    }
    return c;
}
QString escapeString(const QString& s) {
    QString result;
    result.reserve(s.size());
    for (QChar c : s) {
        result.push_back(escapeChar(c));
    }
    return result;
}
bool SerializeWithPromptIfNeeded() {
    QString file_path;
    auto& project = VMTProject::GetInstance();
    if (!project.GetMachines().empty() &&
        VMTProjectSaver::SaveProject(&project)) {
        QMessageBox box;
        box.setText("Project saved");
        box.exec();
        return true;
    }
    return false;
}
}  // namespace utils::ui
