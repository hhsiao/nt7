// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m照夜玉獅子[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這頭照夜獅子通體上下，一色雪白，傳說能日行千里，追風逐電。[2;37;0m
它是顏真卿的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "pen");
        set("owner_name", "顏真卿");
        set_temp("owner", "pen");
        set_temp("owner_name", "顏真卿");
        ::setup();
}
