// =============================================================================
// ir_protocols.h — ORVIBO CT30W 多协议红外空调控制器 协议头文件集合
// 配合 ir_controller_multi.yaml 使用，放在同一目录下
// =============================================================================
#pragma once

#include "IRremoteESP8266.h"
#include "IRsend.h"
#include "IRrecv.h"
#include "IRac.h"
#include "IRutils.h"

// 18 种空调协议
#include "ir_Kelvinator.h"
#include "ir_Gree.h"
#include "ir_Midea.h"
#include "ir_Daikin.h"
#include "ir_Panasonic.h"
#include "ir_LG.h"
#include "ir_Samsung.h"
#include "ir_Toshiba.h"
#include "ir_Fujitsu.h"
#include "ir_Hitachi.h"
#include "ir_Mitsubishi.h"
#include "ir_MitsubishiHeavy.h"
#include "ir_Haier.h"
#include "ir_Tcl.h"
#include "ir_Coolix.h"
#include "ir_Carrier.h"
#include "ir_Sharp.h"
#include "ir_Whirlpool.h"
