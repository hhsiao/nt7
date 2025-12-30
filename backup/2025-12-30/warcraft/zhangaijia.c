// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;31m愛的代價[2;37;0m[2;37;0m", ({"ilovelong"}));        
        set("gender", "男性");                
        set("long", "我愛我的龍龍[2;37;0m
它是張艾嘉的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "zhangaijia");
        set("owner_name", "張艾嘉");
        set_temp("owner", "zhangaijia");
        set_temp("owner_name", "張艾嘉");
        ::setup();
}
