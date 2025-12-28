// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[33m萬年海龜[2;37;0m[2;37;0m", ({"wugui"}));        
        set("gender", "男性");                
        set("long", "打不死的萬年英雄海龜，適合用來實驗武功或暴力發洩！[2;37;0m
它是師太別走的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "lama");
        set("owner_name", "師太別走");
        set_temp("owner", "lama");
        set_temp("owner_name", "師太別走");
        ::setup();
}
