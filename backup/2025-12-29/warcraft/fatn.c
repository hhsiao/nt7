// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻獸六[2;37;0m[2;37;0m", ({"aan"}));        
        set("gender", "女性");                
        set("long", "我的魔幻獸[2;37;0m
它是高藥的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fatn");
        set("owner_name", "高藥");
        set_temp("owner", "fatn");
        set_temp("owner_name", "高藥");
        ::setup();
}
