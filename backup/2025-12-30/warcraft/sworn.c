// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m龜雖壽[2;37;0m[2;37;0m", ({"fangfang"}));        
        set("gender", "男性");                
        set("long", "老驥伏櫪，志在千里，烈士暮年，壯心不已。[2;37;0m
它是浪淘沙的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "sworn");
        set("owner_name", "浪淘沙");
        set_temp("owner", "sworn");
        set_temp("owner_name", "浪淘沙");
        ::setup();
}
