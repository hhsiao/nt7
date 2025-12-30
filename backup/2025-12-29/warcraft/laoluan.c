// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m白蛇[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "話說這個是白娘子.....天天騎，天天騎。色藝！[2;37;0m
它是吾哈老亂的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "laoluan");
        set("owner_name", "吾哈老亂");
        set_temp("owner", "laoluan");
        set_temp("owner_name", "吾哈老亂");
        ::setup();
}
