
# ORVIBO CT30W ESPHome 多协议红外空调控制器

基于 [ORVIBO-CT30W-ESPHome](https://github.com/SrsKbtzw/ORVIBO-CT30W-ESPHome) 项目优化，适配 **IRremoteESP8266 v2.9.0** 和 **ESPHome 2026.6.x**。

## 功能

- 支持 **18 种主流空调红外协议**，通过 Home Assistant / Web UI 下拉选择器实时切换
- 完整空调控制：电源、模式、温度、风速、扫风、灯光、静音、强力
- 红外学码（IR Dump）支持
- 定时关机（SNTP 时间同步）
- Web Server 控制面板

## 支持的协议

| # | 协议 | 类名 |
|---|------|------|
| 0 | Kelvinator (Gree/Sharp) | `IRKelvinatorAC` |
| 1 | Gree | `IRGreeAC` |
| 2 | Midea | `IRMideaAC` |
| 3 | Daikin | `IRDaikinESP` |
| 4 | Panasonic | `IRPanasonicAc` |
| 5 | LG | `IRLgAc` |
| 6 | Samsung | `IRSamsungAc` |
| 7 | Toshiba | `IRToshibaAC` |
| 8 | Fujitsu | `IRFujitsuAC` |
| 9 | Hitachi | `IRHitachiAc` |
| 10 | Mitsubishi Electric | `IRMitsubishiAC` |
| 11 | Mitsubishi Heavy | `IRMitsubishiHeavy152Ac` |
| 12 | Haier | `IRHaierAC` |
| 13 | TCL | `IRTcl112Ac` |
| 14 | Coolix (Beko/Midea) | `IRCoolixAC` |
| 15 | Carrier | `IRCarrierAc64` |
| 16 | Sharp | `IRSharpAc` |
| 17 | Whirlpool | `IRWhirlpoolAc` |

## 硬件要求

- **设备**: ORVIBO CT30W (ESP8266)
- **红外发射**: GPIO 14
- **红外接收**: GPIO 5
- **红外学码按键**: GPIO 4

## 快速开始

### 1. 准备文件

将以下文件放入 ESPHome 配置目录：

```
esphome/
├── ir_controller_multi.yaml     # 主配置文件
└── ir_protocols.h               # 协议头文件
```

### 2. 修改配置

编辑 `ir_controller_multi.yaml`，替换以下占位符：

```yaml
# WiFi 配置
wifi:
  ssid: "YOUR_WIFI_SSID"           # ← 替换为你的 WiFi 名称
  password: "YOUR_WIFI_PASSWORD"   # ← 替换为你的 WiFi 密码

# API 加密密钥（可选，首次编译会自动生成）
api:
  encryption:
    key: "YOUR_API_ENCRYPTION_KEY"  # ← 替换或删除此行让 ESPHome 自动生成
```

### 3. 编译并烧录

```bash
esphome run ir_controller_multi.yaml
```

首次编译会把固件写入 `C:\esphb` 目录（可在 YAML 中修改 `build_path`）。

### 4. 接入 Home Assistant

设备启动后会被 Home Assistant 自动发现。所有实体（电源、模式、温度、风速、扫风等）会自动注册。

## IRremoteESP8266 v2.9.0 兼容性说明

本项目针对 IRremoteESP826 v2.9.0 进行了以下 API 适配修复：

- **类名修正**: `IRWhirlpoolAC` → `IRWhirlpoolAc`、`IRHitachiAC` → `IRHitachiAc`、`IRMitsubishiHeavyAC` → `IRMitsubishiHeavy152Ac`、`IRTclAc` → `IRTcl112Ac`、`IRCarrierAC` → `IRCarrierAc64`、`IRSharpAC` → `IRSharpAc`
- **方法名修正**: Fujitsu `setFan` → `setFanSpeed`
- **签名修正**: `setSwingVertical` 按协议使用不同签名（Kelvinator/Gree 传2参数，Hitachi 传 bool，Panasonic/MitsubishiH/TCL 传 uint8_t，Daikin 传1参数）
- **死代码清理**: 移除各协议不支持的 `setSwingHorizontal`、`setLight`、`setQuiet`、`setTurbo` 等方法
- **`recalc_timestamp_local()`** 适配无参版本

## 项目结构

```
ORVIBO-CT30W-ESPHome/
├── ir_controller_multi.yaml     # ESPHome 主配置（841 行）
├── ir_protocols.h               # 18 种空调协议头文件引用
└── README.md                    # 本文件
```

## 打赏

如果这个项目对你有帮助，欢迎请我喝杯咖啡 ☕

![打赏码](donate.jpg)

## 许可

MIT License

