// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m雪影[2;37;0m[2;37;0m", ({"flyfox"}));        
        set("gender", "男性");                
        set("long", "雪山飛狐，踏雪無痕，冰魂雪魄，集螢映雪[2;37;0m
它是冰雪兒的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "icer");
        set("owner_name", "冰雪兒");
        set_temp("owner", "icer");
        set_temp("owner_name", "冰雪兒");
        ::setup();
}
