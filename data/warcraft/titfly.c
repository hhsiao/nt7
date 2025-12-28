// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小葉[2;37;0m[2;37;0m", ({"palaxiao"}));        
        set("gender", "女性");                
        set("long", "小葉[2;37;0m
它是提坦莉婭的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "titfly");
        set("owner_name", "提坦莉婭");
        set_temp("owner", "titfly");
        set_temp("owner_name", "提坦莉婭");
        ::setup();
}
