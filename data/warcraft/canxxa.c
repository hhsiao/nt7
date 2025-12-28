// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大貓[2;37;0m[2;37;0m", ({"cat"}));        
        set("gender", "男性");                
        set("long", "好大的一隻貓啊[2;37;0m
它是獵戶座的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "canxxa");
        set("owner_name", "獵戶座");
        set_temp("owner", "canxxa");
        set_temp("owner_name", "獵戶座");
        ::setup();
}
