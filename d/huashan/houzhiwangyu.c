#include <ansi.h>
inherit ROOM;

void message_competition(string msg);
void create() {
    set("short", "猴子望月");
    set("long", @LONG
此處原是一仞高聳入雲的峭壁，不知何年由人從峭壁的半腰硬是
開出一條棧道來，棧道旁有一粗十餘丈的擎天石柱，石柱頂生一鬆，
松旁有一天生奇石，宛如翹首望月的猴子。
LONG );
    set("exits", ([ /* sizeof() == 3 */
        "southdown" : __DIR__"liyubei",
    /*
     * "northup" : "/adm/npc/huashanjueding",
     * "up" : "/adm/npc/kantai",
     * "1" : "/adm/npc/biwu1",
     * "2" : "/adm/npc/biwu2",
     * "3" : "/adm/npc/biwu3",
     * "4" : "/adm/npc/biwu4",
     */
    ]));

    set("outdoors", "huashan" );

    set("no_fight", 1);
    setup();
}

void init() {
    if ((wiz_level(this_player()) >= 5) || query("id", this_player())=="lazy cat")
    {
        add_action("do_open", "open");
        add_action("do_close", "close");
    }
}

int do_open() {
    object me = this_player();

    if (query("exits/up"))
        return notify_fail("門已經是開著的了。\n");

    set("exits", ([ /* sizeof() == 3 */
        "southdown" : __DIR__"liyubei",
        "northup" : "/adm/npc/huashanjueding",
        "up" : "/adm/npc/kantai",
        "1" : "/adm/npc/biwu1",
        "2" : "/adm/npc/biwu2",
        "3" : "/adm/npc/biwu3",
    //                      "4" : "/adm/npc/biwu4"
    ]));

    message_vision(HIY "$N" HIY "輕輕一推，將通向武林大會會場的"
        "大門開啟了。\n" NOR, me);

    shout(HIY "【華山論劍】" NOR + WHT + me->name() + WHT "[" +
        query("id", me) + WHT"]開啟了華山絕頂的武林大會會場。\n"NOR);

    return 1;
}

int do_close() {
    object me = this_player();

    if (! query("exits/up"))
        return notify_fail("門已經是關著的了。\n");

    set("exits", ([ /* sizeof() == 3 */
        "southdown" : __DIR__"liyubei"
        ]));
    message_vision(WHT "$N" WHT "順手一帶，將通向武林大會會場的"
        "大門關上了。\n" NOR, me);
    return 1;
}

void message_competition(string msg) {
    CHANNEL_D->channel_broadcast("rumor", msg);
}

int valid_leave(object me, string dir) {
    int i;
    object *inv;

    if (!playerp(me) && dir != "southdown") return -1;

    if (dir == "southdown" || dir == "up")
        return 1;

    //        set_temp("flag_hslj", 1, me);

    inv = deep_inventory(me);

    if(dir != "northup" )
        for(i = sizeof(inv) - 1; i>=0; i--)
    {
        if (inv[i]->is_xpzhu()) continue;

        if (me->query_condition("killer"))
            return notify_fail("殺人者不可以進入比武場！！！\n");

        if (! wizardp(me) &&
            inv[i]->is_cruise_ob())
            return notify_fail("不可以攜帶"+inv[i]->name(1) + "進入比武場！！！\n");

        if (! wizardp(me) &&
            inv[i]->is_item_make())
            return notify_fail("不可以攜帶"+inv[i]->name(1) + "進入比武場！！！\n");

        if (! wizardp(me) &&
            query("weapon_prop", inv[i]) )
            return notify_fail("不可以攜帶"+inv[i]->name(1) + "進入比武場！！！\n");

        if (! wizardp(me) &&
            query("armor_prop", inv[i]) )
            return notify_fail("不可以攜帶"+inv[i]->name(1) + "進入比武場！！！\n");
    }

    if (wizardp(me)) {
        return 1;
    }

    if (dir == "1" && query("level", me) >= 20 && query("level", me) <= 100) {
        message_competition((ultrap(me) ? "大宗師" : "") +
            me->name(1) + "進入華山絕頂的1號比武場。");
        set_temp("flag_hslj", 1, me);
        BUFF_D->debuff(me, "powerofsun", "bless");
        BUFF_D->debuff(me, "powerofmoon", "bless");
        BUFF_D->debuff(me, "powerofstar", "bless");
        return 1;
    }
    if (dir == "2" && query("level", me) >= 101 && query("level", me) <= 200) {
        message_competition((ultrap(me) ? "大宗師" : "") +
            me->name(1) + "進入華山絕頂的2號比武場。");
        set_temp("flag_hslj", 2, me);
        BUFF_D->debuff(me, "powerofsun", "bless");
        BUFF_D->debuff(me, "powerofmoon", "bless");
        BUFF_D->debuff(me, "powerofstar", "bless");
        return 1;
    }
    if (dir == "3" && query("level", me) >= 201) {
        message_competition((ultrap(me) ? "大宗師" : "") +
            me->name(1) + "進入華山絕頂的3號比武場。");
        set_temp("flag_hslj", 3, me);
        BUFF_D->debuff(me, "powerofsun", "bless");
        BUFF_D->debuff(me, "powerofmoon", "bless");
        BUFF_D->debuff(me, "powerofstar", "bless");
        return 1;
    }
    if (dir == "4" && query("level", me) >= 20) {
        message_competition((ultrap(me) ? "大宗師" : "") +
            me->name(1) + "進入華山絕頂的4號比武場。");
        set_temp("flag_hslj", 4, me);
        BUFF_D->debuff(me, "powerofsun", "bless");
        BUFF_D->debuff(me, "powerofmoon", "bless");
        BUFF_D->debuff(me, "powerofstar", "bless");
        return 1;
    }

    if (dir == "northup")
    {
        if (me->query_condition("killer"))
            return notify_fail("殺人者不可以進入比武場！！！\n");
        message_competition((ultrap(me) ? "大宗師" : "") +
            me->name(1) + "進入華山絕頂的論劍比武場。");
        set_temp("flag_hslj", 5, me);
        return 1;
    }

    return notify_fail("你不可以到那邊比武！！\n");
}
