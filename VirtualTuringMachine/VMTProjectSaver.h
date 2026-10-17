#pragma once

#include <QString>
#include <mutex>

#include "vmtproject.h"

class VMTProjectSaver {
   public:
    /**
     * @brief Save project (multi thread save)
     *
     * @return true if saved, false otherwise
     */
    static bool SaveProject(VMTProject* project);

   private:
    static QString GetProjectFileName();
    static std::mutex save_mutex_;
};
