// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("禽獸虎[2;37;0m[2;37;0m", ({"qsh"}));        
        set("gender", "女性");                
        set("long", "禽獸虎[2;37;0m
它是賤人賤的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "cescjr");
        set("owner_name", "賤人賤");
        set_temp("owner", "cescjr");
        set_temp("owner_name", "賤人賤");
        ::setup();
}
