// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m星辰[2;37;0m[2;37;0m", ({"cnn"}));        
        set("gender", "女性");                
        set("long", "一隻威嚴冷酷的純白大虎，眼睛裡透出綠幽幽的光芒。[2;37;0m
它是遊戲人生的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "chen");
        set("owner_name", "遊戲人生");
        set_temp("owner", "chen");
        set_temp("owner_name", "遊戲人生");
        ::setup();
}
