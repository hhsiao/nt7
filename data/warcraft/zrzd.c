// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m長[1;37m[1;36m澤[1;36m[2;37;0m[2;37;0m", ({"changze"}));        
        set("gender", "女性");                
        set("long", "AV女優[2;37;0m
它是粽四的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "zrzd");
        set("owner_name", "粽四");
        set_temp("owner", "zrzd");
        set_temp("owner_name", "粽四");
        ::setup();
}
