// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m叼毛獸[2;37;0m[2;37;0m", ({"tjt"}));        
        set("gender", "女性");                
        set("long", "這隻與時代格格不入的二次元神獸正以一副猥瑣的表情痴痴地望著你[2;37;0m
它是張小豐的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wdpt");
        set("owner_name", "張小豐");
        set_temp("owner", "wdpt");
        set_temp("owner_name", "張小豐");
        ::setup();
}
