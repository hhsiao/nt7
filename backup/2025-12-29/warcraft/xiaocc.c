// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m火[1;35m麒[1;33m麟[2;37;0m[2;37;0m", ({"qiqi"}));        
        set("gender", "男性");                
        set("long", "你按照狂風的指點開始飛快的念道[2;37;0m
它是無情楓的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xiaocc");
        set("owner_name", "無情楓");
        set_temp("owner", "xiaocc");
        set_temp("owner_name", "無情楓");
        ::setup();
}
