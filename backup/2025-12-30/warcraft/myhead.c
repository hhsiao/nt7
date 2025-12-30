// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m一片雲彩[1;37m[2;37;0m[2;37;0m", ({"myid"}));        
        set("gender", "女性");                
        set("long", "$HIW$一片雲彩$HIW$[2;37;0m
它是家傳帽子的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "myhead");
        set("owner_name", "家傳帽子");
        set_temp("owner", "myhead");
        set_temp("owner_name", "家傳帽子");
        ::setup();
}
