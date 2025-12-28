// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m禿驢[2;37;0m[2;37;0m", ({"foxza"}));        
        set("gender", "男性");                
        set("long", "一隻和尚騎的小毛驢[2;37;0m
它是皮皮豬的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "foxz");
        set("owner_name", "皮皮豬");
        set_temp("owner", "foxz");
        set_temp("owner_name", "皮皮豬");
        ::setup();
}
