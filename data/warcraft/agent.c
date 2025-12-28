// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m阿斯頓馬丁[2;37;0m[2;37;0m", ({"astonmartin"}));        
        set("gender", "男性");                
        set("long", "阿斯頓馬丁DBS，它是著名間諜007最愛的一輛座駕。[2;37;0m
它是零零七的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "agent");
        set("owner_name", "零零七");
        set_temp("owner", "agent");
        set_temp("owner_name", "零零七");
        ::setup();
}
