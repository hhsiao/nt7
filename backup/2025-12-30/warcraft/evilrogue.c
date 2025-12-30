// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[30m命裡欠揍[2;37;0m[2;37;0m[2;37;0m", ({"rascal"}));        
        set("gender", "男性");                
        set("long", "命裡欠抽！[2;37;0m
它是五行缺德的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "evilrogue");
        set("owner_name", "五行缺德");
        set_temp("owner", "evilrogue");
        set_temp("owner_name", "五行缺德");
        ::setup();
}
