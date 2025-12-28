// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m諾倫斯[2;37;0m[2;37;0m", ({"lion"}));        
        set("gender", "女性");                
        set("long", "神獸諾倫斯[2;37;0m
它是萊維的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "lionheart");
        set("owner_name", "萊維");
        set_temp("owner", "lionheart");
        set_temp("owner_name", "萊維");
        ::setup();
}
