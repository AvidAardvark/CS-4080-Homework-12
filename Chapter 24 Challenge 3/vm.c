
case OBJ_NATIVE: {
    NativeFn native = AS_NATIVE(callee);
    Value result;
    if (!native(argCount, vm.stackTop - argCount, &result)) {
        return false;
    }
    vm.stackTop -= argCount + 1;
    push(result);
    return true;
}

static Value clockNative(int argCount, Value* args) {
    return NUMBER_VAL((double)clock() / CLOCKS_PER_SEC);
}

static bool sqrtNative(int argCount, Value* args, Value* result) {
    if (argCount != 1) {
        runtimeError("sqrt() expects 1 argument.");
        return false;
    }

    if (!IS_NUMBER(args[0])) {
        runtimeError("sqrt() argument must be a number.");
        return false;
    }

    double x = AS_NUMBER(args[0]);
    if (x < 0) {
        runtimeError("sqrt() argument must be non-negative.");
        return false;
    }

    *result = NUMBER_VAL(sqrt(x));
    return true;
}

defineNative("clock", clockNative);
defineNative("sqrt", sqrtNative);
