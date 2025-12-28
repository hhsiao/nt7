// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m起司喵喵[2;37;0m[2;37;0m", ({"cheese"}));        
        set("gender", "女性");                
        set("long", "這是一隻綠茶婊，後來被抓來給人騎了[2;37;0m
它是天幻的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kennyg");
        set("owner_name", "天幻");
        set_temp("owner", "kennyg");
        set_temp("owner_name", "天幻");
        ::setup();
}
