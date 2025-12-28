// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;32m嘰咕[2;37;0m[2;37;0m[2;37;0m", ({"jigu"}));        
        set("gender", "女性");                
        set("long", "$BLINK$$HIG$嘰咕$NOR$[2;37;0m
它是嘰嘰咕咕的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "mutter");
        set("owner_name", "嘰嘰咕咕");
        set_temp("owner", "mutter");
        set_temp("owner_name", "嘰嘰咕咕");
        ::setup();
}
