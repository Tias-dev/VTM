#include "VMTProjectSaver.h"

#include <qlogging.h>

#include <mutex>

#include "VMTJsonSerializer.h"
#include "configuration.h"

std::mutex VMTProjectSaver::save_mutex_{};

QString VMTProjectSaver::GetProjectFileName() {
    QString name = VMTProject::GetInstance().GetLocation();
    name += "/";
    name += VMTProject::GetInstance().GetName();
    name += ".vmt.json";
    return name;
}

bool VMTProjectSaver::SaveProject(VMTProject* project) {
    std::unique_lock<std::mutex> lock(save_mutex_);
    QString name = GetProjectFileName();
    VMTJsonSerializer serializer(name);
    if (!serializer.serialize(project)) {
        return false;
    }

    Configuration::GetInstance().AddRecentProject(name);
    Configuration::GetInstance().Save();
    qDebug() << "Project saved";
    return true;
}
