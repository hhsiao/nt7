// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[37m波斯貓[2;37;0m[2;37;0m", ({"snowcat"}));        
        set("gender", "男性");                
        set("long", "一隻溫順的波斯貓，正在懶懶的嗮太陽.[2;37;0m
它是飛雪的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "snow");
        set("owner_name", "飛雪");
        set_temp("owner", "snow");
        set_temp("owner_name", "飛雪");
        ::setup();
}
