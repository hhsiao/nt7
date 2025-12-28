// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("三角小木馬[2;37;0m[2;37;0m", ({"min"}));        
        set("gender", "女性");                
        set("long", "我有一隻三角小木馬 有一天我心血來潮 騎著去趕集 ...[2;37;0m
它是周秀娜的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "cfe");
        set("owner_name", "周秀娜");
        set_temp("owner", "cfe");
        set_temp("owner_name", "周秀娜");
        ::setup();
}
