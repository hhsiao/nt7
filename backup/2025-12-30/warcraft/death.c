// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m睚眥[2;37;0m[2;37;0m", ({"revenge"}));        
        set("gender", "男性");                
        set("long", "龍身豺首,性格剛烈,嗜殺好鬥,一飯之德必償,睚眥之怨必報![2;37;0m
它是死性不改的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "death");
        set("owner_name", "死性不改");
        set_temp("owner", "death");
        set_temp("owner_name", "死性不改");
        ::setup();
}
