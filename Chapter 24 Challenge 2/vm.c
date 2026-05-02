      case OBJ_NATIVE: {
        NativeFn native = AS_NATIVE(callee);
        if (native(argCount, vm.stackTop - argCount)) {
          vm.stackTop -= argCount;
          return true;
        } else {
          runtimeError(AS_STRING(vm.stackTop[-argCount - 1])->chars);
          return false;
        }
      }
