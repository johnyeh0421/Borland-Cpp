object Form1: TForm1
  Left = 396
  Top = 712
  Width = 823
  Height = 181
  Caption = 'HMAC SHA1 Tool _JohnYeh v100'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 16
    Width = 58
    Height = 36
    Caption = 'Text'
    Font.Charset = JOHAB_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 24
    Top = 59
    Width = 144
    Height = 36
    Caption = 'Secret Key'
    Font.Charset = JOHAB_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 24
    Top = 99
    Width = 100
    Height = 36
    Caption = '=> KEY'
    Font.Charset = JOHAB_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 96
    Top = 16
    Width = 697
    Height = 44
    Font.Charset = JOHAB_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnKeyUp = showKey
  end
  object Edit2: TEdit
    Left = 184
    Top = 59
    Width = 609
    Height = 36
    Font.Charset = JOHAB_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnKeyUp = showKey
  end
  object Edit3: TEdit
    Left = 136
    Top = 96
    Width = 657
    Height = 36
    Font.Charset = JOHAB_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
  end
end
