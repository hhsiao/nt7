// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;32m嘰喳[2;37;0m[2;37;0m[2;37;0m", ({"jizha"}));        
        set("gender", "女性");                
        set("long", "$BLINK$$HIG$嘰喳$NOR$[2;37;0m
它是嘰嘰喳喳的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "twitter");
        set("owner_name", "嘰嘰喳喳");
        set_temp("owner", "twitter");
        set_temp("owner_name", "嘰嘰喳喳");
        ::setup();
}
