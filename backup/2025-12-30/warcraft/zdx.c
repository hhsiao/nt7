// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m命根子[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "$HIB$命根子[2;37;0m
它是東方紅的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "zdx");
        set("owner_name", "東方紅");
        set_temp("owner", "zdx");
        set_temp("owner_name", "東方紅");
        ::setup();
}
