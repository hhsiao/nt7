// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("你妹[2;37;0m[2;37;0m", ({"nimei"}));        
        set("gender", "女性");                
        set("long", "你妹[2;37;0m
它是萬輪法王的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ride");
        set("owner_name", "萬輪法王");
        set_temp("owner", "ride");
        set_temp("owner_name", "萬輪法王");
        ::setup();
}
