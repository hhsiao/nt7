// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m玄龜[2;37;0m[2;37;0m", ({"xuan_gui"}));        
        set("gender", "男性");                
        set("long", "如煙如霧，似乎沒有實體的聖獸[2;37;0m
它是樓穎的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "mine");
        set("owner_name", "樓穎");
        set_temp("owner", "mine");
        set_temp("owner_name", "樓穎");
        ::setup();
}
