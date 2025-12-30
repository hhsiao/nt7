// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("睡袋[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "女性");                
        set("long", "好大啊[2;37;0m
它是塗鴉人生的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "mlove");
        set("owner_name", "塗鴉人生");
        set_temp("owner", "mlove");
        set_temp("owner_name", "塗鴉人生");
        ::setup();
}
