// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小老虎[2;37;0m[2;37;0m", ({"laohu"}));        
        set("gender", "男性");                
        set("long", "小老虎[2;37;0m
它是梅瑟苔絲的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "msds");
        set("owner_name", "梅瑟苔絲");
        set_temp("owner", "msds");
        set_temp("owner_name", "梅瑟苔絲");
        ::setup();
}
