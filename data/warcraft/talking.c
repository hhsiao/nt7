// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;32m嘰歪[2;37;0m[2;37;0m[2;37;0m", ({"jiwai"}));        
        set("gender", "女性");                
        set("long", "$BLINK$$HIG$嘰歪$NOR$[2;37;0m
它是嘰嘰歪歪的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "talking");
        set("owner_name", "嘰嘰歪歪");
        set_temp("owner", "talking");
        set_temp("owner_name", "嘰嘰歪歪");
        ::setup();
}
