// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m叼毛獸[2;37;0m[2;37;0m", ({"dms"}));        
        set("gender", "女性");                
        set("long", "這隻與時代格格不入的二次元神獸正以一副猥瑣的表情痴痴地望著你[2;37;0m
它是趙日天的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "newsboy");
        set("owner_name", "趙日天");
        set_temp("owner", "newsboy");
        set_temp("owner_name", "趙日天");
        ::setup();
}
