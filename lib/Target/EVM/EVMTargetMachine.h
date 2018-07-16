//===-- EVMTargetMachine.h - Define TargetMachine for EVM ---*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the EVM specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_EVM_EVMTARGETMACHINE_H
#define LLVM_LIB_TARGET_EVM_EVMTARGETMACHINE_H

#include "llvm/CodeGen/SelectionDAGTargetInfo.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
class EVMTargetMachine : public LLVMTargetMachine {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;

public:
  EVMTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                     StringRef FS, const TargetOptions &Options,
                     Optional<Reloc::Model> RM, Optional<CodeModel::Model> CM,
                     CodeGenOpt::Level OL, bool JIT);

  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;


  TargetLoweringObjectFile *getObjFileLowering() const override {
    return TLOF.get();
  }

  // TargetMachine interface
public:
  virtual bool addPassesToEmitFile(llvm::legacy::PassManagerBase &, raw_pwrite_stream &, raw_pwrite_stream *, CodeGenFileType, bool, MachineModuleInfo *MMI) override;
  virtual bool addPassesToEmitMC(llvm::legacy::PassManagerBase &, MCContext *&, raw_pwrite_stream &, bool) override;
};
}

#endif
