// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("梅毒[2;37;0m[2;37;0m", ({"girlioi"}));        
        set("gender", "女性");                
        set("long", "快來騎我 保證你中獎[2;37;0m
它是愛滋病的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "aids");
        set("owner_name", "愛滋病");
        set_temp("owner", "aids");
        set_temp("owner_name", "愛滋病");
        ::setup();
}
