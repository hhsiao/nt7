// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("一隻紅鳥[2;37;0m[2;37;0m", ({"xieg"}));        
        set("gender", "男性");                
        set("long", "一隻紅鳥[2;37;0m
它是伯賞昆遇的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "scdyxieg");
        set("owner_name", "伯賞昆遇");
        set_temp("owner", "scdyxieg");
        set_temp("owner_name", "伯賞昆遇");
        ::setup();
}
