// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m愛犬小白[2;37;0m[2;37;0m", ({"mydog"}));        
        set("gender", "男性");                
        set("long", "夢旅人現實生活中的愛犬，2013年2月離開了世界，享年8歲。[2;37;0m
它是夢旅人的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "dreambp");
        set("owner_name", "夢旅人");
        set_temp("owner", "dreambp");
        set_temp("owner_name", "夢旅人");
        ::setup();
}
