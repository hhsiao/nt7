// This program is a part of NITAN MudLIB
// redl 2013/9
#include <ansi.h>
#include <room.h>
inherit __DIR__"normal.c";

void create() {
    set("short", "傳功樓");
    set("long",
        "傳功樓所有建築都是用一種赤紅色的奇異石材所築，臺階欄杆，莫不如\n"
        "此。整個傳功樓高大雄偉，呈現出寶塔形狀，共有三層，每高一層，便比下\n"
        "面小了一半左右，但是每一層看上去幾乎都有不可思議的十丈之高。遠遠往\n"
        "上望去，整個傳功樓如若一團巨大燃燒的赤紅火焰，直刺蒼穹，站在樓下，\n"
        "如同螻蟻一般，頓感渺小無法往上移步。\n"
    );
    //set("outdoors", "dongtian");
    set("exits",([ /* sizeof() == 1 */
        "west": __DIR__"zoulang24",
        "up": __DIR__"chuangonglou2"
        ]));

    set("no_steal", 1);
    set("no_beg", 1);
    set("no_rideto", 1);
    set("no_flyto", 1);
    set("no_drift", 1);
    set("no_sleep_room", 1);
    set("max_carry_user" , 3);
    //        set("owner_level", 1);可以傳授給外人，隱身者和冒險者等等

    setup();
}

int valid_leave(object me, string dir) {

    if(query("dongtian/chuangong/visit_time", me)>time() && wiz_level(me) < 5 && dir=="up") {
        tell_object(me, NOR "你等一段時間才能再上去。\n" NOR);
        me->start_busy(2);
        return -1;
    }

    return ::valid_leave(me, dir);
}

void init() {
    object me = this_player();

    if (playerp(me)) write(NOR "脫下所有東西，包括鞋襪再上二樓去，千萬不要自誤。\n" NOR);

    ::init();
}
