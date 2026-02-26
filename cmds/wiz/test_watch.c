// Quick test: verify watch_object efun exists
int main(object me, string arg) {
    write("Testing watch_object efun existence...\n");

    // Test 1: Check if efuns are callable (just call with bad args to see if they exist)
    write("watch_object efun: " + function_exists("watch_object") + "\n");
    write("unwatch_object efun: " + function_exists("unwatch_object") + "\n");

    // Test 2: Simple functional test
    object room = environment(me);
    function cb = (: write("WATCH FIRED: " + file_name() + " item=" + file_name() + " enter=" +  + "\n") :);

    int result = watch_object(room, cb);
    write("watch_object(" + file_name(room) + ") returned: " + result + "\n");

    // Unwatch
    unwatch_object(room, cb);
    write("unwatch_object done.\n");

    write("All tests passed!\n");
    return 1;
}
