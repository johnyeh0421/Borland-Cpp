object Form1: TForm1
  Left = 355
  Top = 201
  Width = 343
  Height = 589
  Caption = 'SerialPort Client Tool'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 136
    Top = 6
    Width = 22
    Height = 32
    Brush.Color = clRed
    Shape = stRoundSquare
  end
  object Setup: TButton
    Left = 8
    Top = 8
    Width = 41
    Height = 25
    Caption = 'Setup'
    TabOrder = 0
    OnClick = SetupClick
  end
  object Start: TButton
    Left = 48
    Top = 8
    Width = 41
    Height = 25
    Caption = 'Start'
    TabOrder = 1
    OnClick = StartClick
  end
  object Stop: TButton
    Left = 88
    Top = 8
    Width = 41
    Height = 25
    Caption = 'Stop'
    TabOrder = 2
    OnClick = StopClick
  end
  object Plot: TButton
    Left = 165
    Top = 8
    Width = 41
    Height = 25
    Caption = 'Plot'
    TabOrder = 3
  end
  object Save: TButton
    Left = 205
    Top = 8
    Width = 41
    Height = 25
    Caption = 'Save'
    TabOrder = 4
  end
  object Load: TButton
    Left = 245
    Top = 8
    Width = 41
    Height = 25
    Caption = 'Load'
    TabOrder = 5
  end
  object Clear: TButton
    Left = 285
    Top = 8
    Width = 41
    Height = 25
    Caption = 'Clear'
    TabOrder = 6
    OnClick = ClearClick
  end
  object Display_Format: TGroupBox
    Left = 8
    Top = 40
    Width = 201
    Height = 41
    Caption = 'Display Format'
    TabOrder = 7
    object Display_Hex: TRadioButton
      Left = 8
      Top = 16
      Width = 49
      Height = 17
      Caption = 'Hex'
      TabOrder = 0
    end
    object Display_Numeric: TRadioButton
      Left = 128
      Top = 16
      Width = 65
      Height = 17
      Caption = 'Numeric'
      TabOrder = 1
    end
    object Display_ASCII: TRadioButton
      Left = 64
      Top = 16
      Width = 49
      Height = 17
      Caption = 'ASCII'
      TabOrder = 2
    end
  end
  object Memo1: TMemo
    Left = 0
    Top = 88
    Width = 321
    Height = 281
    Cursor = crArrow
    Lines.Strings = (
      '')
    ScrollBars = ssBoth
    TabOrder = 8
  end
  object Edit1: TEdit
    Left = 8
    Top = 376
    Width = 257
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    OnChange = Edit1Change
  end
  object Send_Asc: TButton
    Left = 264
    Top = 376
    Width = 57
    Height = 25
    Caption = 'Send-Asc'
    TabOrder = 10
    OnClick = Send_AscClick
  end
  object Send_Format: TGroupBox
    Left = 8
    Top = 408
    Width = 201
    Height = 41
    Caption = 'Send Format'
    TabOrder = 11
    object Send_Hex: TRadioButton
      Left = 8
      Top = 16
      Width = 57
      Height = 17
      Caption = 'Hex'
      TabOrder = 0
    end
    object Send_ASCII: TRadioButton
      Left = 72
      Top = 16
      Width = 65
      Height = 17
      Caption = 'ASCII'
      TabOrder = 1
    end
    object Send_Numeric: TRadioButton
      Left = 136
      Top = 16
      Width = 57
      Height = 17
      Caption = 'Numeric'
      TabOrder = 2
    end
  end
  object Auto_Send: TGroupBox
    Left = 216
    Top = 408
    Width = 105
    Height = 41
    Caption = 'Auto Send'
    TabOrder = 12
    object Label1: TLabel
      Left = 80
      Top = 16
      Width = 18
      Height = 16
      Caption = 'ms'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object auto_sd: TCheckBox
      Left = 8
      Top = 16
      Width = 17
      Height = 17
      TabOrder = 0
    end
    object auto_send_time: TEdit
      Left = 24
      Top = 16
      Width = 57
      Height = 21
      TabOrder = 1
      Text = '1000'
    end
  end
  object Last_Receive_Time: TGroupBox
    Left = 8
    Top = 456
    Width = 201
    Height = 45
    Caption = 'Last Receive Time'
    TabOrder = 13
    object last_recv_time: TCheckBox
      Left = 8
      Top = 20
      Width = 185
      Height = 17
      Caption = '2015/7/9 '#19979#21320' 12:00:00'
      TabOrder = 0
    end
  end
  object Byte_Count: TGroupBox
    Left = 216
    Top = 456
    Width = 105
    Height = 45
    Caption = 'Byte Count'
    TabOrder = 14
    object byte_ct: TCheckBox
      Left = 8
      Top = 20
      Width = 89
      Height = 17
      Caption = '0'
      TabOrder = 0
    end
  end
  object ASCII_Line_Change_Character: TGroupBox
    Left = 8
    Top = 504
    Width = 233
    Height = 41
    Caption = 'ASCII Line Change Character'
    TabOrder = 15
    object LFCR: TRadioButton
      Left = 180
      Top = 16
      Width = 49
      Height = 17
      Caption = 'LFCR'
      TabOrder = 0
    end
    object CR: TRadioButton
      Left = 48
      Top = 16
      Width = 41
      Height = 17
      Caption = 'CR'
      TabOrder = 1
    end
    object CRLF: TRadioButton
      Left = 128
      Top = 16
      Width = 49
      Height = 17
      Caption = 'CRLF'
      TabOrder = 2
    end
    object LF: TRadioButton
      Left = 88
      Top = 16
      Width = 33
      Height = 17
      Caption = 'LF'
      TabOrder = 3
    end
    object No: TRadioButton
      Left = 8
      Top = 16
      Width = 41
      Height = 17
      Caption = 'No'
      TabOrder = 4
    end
  end
  object Auto_Log: TGroupBox
    Left = 248
    Top = 504
    Width = 73
    Height = 41
    Caption = 'Auto Log'
    TabOrder = 16
    object Label2: TLabel
      Left = 56
      Top = 16
      Width = 7
      Height = 16
      Caption = 's'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object auto_log_time: TEdit
      Left = 26
      Top = 16
      Width = 25
      Height = 21
      TabOrder = 0
      Text = '60'
    end
    object auto_lg: TCheckBox
      Left = 8
      Top = 16
      Width = 17
      Height = 17
      TabOrder = 1
    end
  end
  object AT: TCheckBox
    Left = 216
    Top = 48
    Width = 81
    Height = 25
    Caption = 'Always Top'
    TabOrder = 17
  end
  object StaticText1: TStaticText
    Left = 143
    Top = 12
    Width = 11
    Height = 20
    Caption = '1'
    Color = clRed
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    TabOrder = 18
  end
  object author: TButton
    Left = 304
    Top = 48
    Width = 17
    Height = 33
    Caption = '?'
    TabOrder = 19
    OnClick = authorClick
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 1
    OnTimer = Timer1Timer
    Left = 112
    Top = 320
  end
  object Timer2: TTimer
    Interval = 1
    OnTimer = Timer2Timer
    Left = 160
    Top = 320
  end
  object Timer3: TTimer
    Enabled = False
    Interval = 1
    OnTimer = Timer3Timer
    Left = 200
    Top = 320
  end
  object Timer4: TTimer
    Enabled = False
    Interval = 1
    OnTimer = Timer4Timer
    Left = 248
    Top = 328
  end
  object SaveDialog1: TSaveDialog
    Left = 40
    Top = 328
  end
  object ComPort1: TComPort
    BaudRate = br9600
    Port = 'COM1'
    Parity.Bits = prNone
    StopBits = sbOneStopBit
    DataBits = dbEight
    Events = [evRxChar, evTxEmpty, evRxFlag, evRing, evBreak, evCTS, evDSR, evError, evRLSD, evRx80Full]
    FlowControl.OutCTSFlow = False
    FlowControl.OutDSRFlow = False
    FlowControl.ControlDTR = dtrDisable
    FlowControl.ControlRTS = rtsDisable
    FlowControl.XonXoffOut = False
    FlowControl.XonXoffIn = False
    StoredProps = [spBasic]
    TriggersOnRxChar = True
    Left = 72
    Top = 280
  end
end
