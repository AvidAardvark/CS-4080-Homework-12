static bool typeNative(int argCount, Value* args, Value* result) {
    if (argCount != 1) {
        runtimeError("type() expects 1 argument.");
        return false;
    }

    Value value = args[0];

    if (IS_NUMBER(value)) {
        *result = OBJ_VAL(copyString("number", 6));
    } else if (IS_BOOL(value)) {
        *result = OBJ_VAL(copyString("bool", 4));
    } else if (IS_NIL(value)) {
        *result = OBJ_VAL(copyString("nil", 3));
    } else if (IS_STRING(value)) {
        *result = OBJ_VAL(copyString("string", 6));
    } else if (IS_FUNCTION(value)) {
        *result = OBJ_VAL(copyString("function", 8));
    } else if (IS_NATIVE(value)) {
        *result = OBJ_VAL(copyString("native", 6));
    } else {
        *result = OBJ_VAL(copyString("unknown", 7));
    }
}

defineNative("clock", clockNative);
defineNative("sqrt", sqrtNative);
defineNative("type", typeNative);
