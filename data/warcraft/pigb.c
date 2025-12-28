// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m和諧神獸[2;37;0m[2;37;0m", ({"pigbb"}));        
        set("gender", "男性");                
        set("long", "一切和諧為主，哪怕捨棄國家利益也沒關係。。。[2;37;0m
它是胡緊韜的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "pigb");
        set("owner_name", "胡緊韜");
        set_temp("owner", "pigb");
        set_temp("owner_name", "胡緊韜");
        ::setup();
}
