#ifndef VMTUNDOELEMENTEDITOR_H
#define VMTUNDOELEMENTEDITOR_H

#include "uicanvas.h"
#include "vmtundoelement.h"

class VMTUndoElementEditor : public VMTUndoElement {
   protected:
    UICanvasState _state;

   public:
    VMTUndoElementEditor(IVMTEnvironment*);
    void Undo(IVMTEnvironment*) override;
};

#endif  // VMTUNDOELEMENTEDITOR_H
