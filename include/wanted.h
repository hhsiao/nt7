
 int is_wanted(object me)
 {
        if (me->query_condition("killer")) {
                notify_fail("你還是了結完江湖恩怨再說吧。\n");
                return 1;
        }
        if (sizeof(filter_array(deep_inventory(me), (: userp :)))) {
                notify_fail("你想販賣人口啊。\n");
                return 1;
        }
        return 0;
 }

