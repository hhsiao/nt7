// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m白龍馬[2;37;0m[2;37;0m", ({"huoju"}));        
        set("gender", "男性");                
        set("long", "白龍馬[2;37;0m
它是歸來王者的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "mudking");
        set("owner_name", "歸來王者");
        set_temp("owner", "mudking");
        set_temp("owner_name", "歸來王者");
        ::setup();
}
