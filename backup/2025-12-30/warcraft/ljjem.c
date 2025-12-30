// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m紅玫瑰[2;37;0m[2;37;0m", ({"redcake"}));        
        set("gender", "女性");                
        set("long", "紅色玫瑰[2;37;0m
它是飄雪掌的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ljjem");
        set("owner_name", "飄雪掌");
        set_temp("owner", "ljjem");
        set_temp("owner_name", "飄雪掌");
        ::setup();
}
