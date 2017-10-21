<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class form1
    Inherits System.Windows.Forms.Form

    'Form 覆寫 Dispose 以清除元件清單。
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    '為 Windows Form 設計工具的必要項
    Private components As System.ComponentModel.IContainer

    '注意:  以下為 Windows Form 設計工具所需的程序
    '可以使用 Windows Form 設計工具進行修改。
    '請不要使用程式碼編輯器進行修改。
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Me.txtguess = New System.Windows.Forms.TextBox()
        Me.btnok = New System.Windows.Forms.Button()
        Me.btnreset = New System.Windows.Forms.Button()
        Me.btnexit = New System.Windows.Forms.Button()
        Me.txttop = New System.Windows.Forms.Label()
        Me.ToolTip1 = New System.Windows.Forms.ToolTip(Me.components)
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.txtsmall = New System.Windows.Forms.TextBox()
        Me.txtlarge = New System.Windows.Forms.TextBox()
        Me.done = New System.Windows.Forms.Button()
        Me.ToolTip2 = New System.Windows.Forms.ToolTip(Me.components)
        Me.ToolTip3 = New System.Windows.Forms.ToolTip(Me.components)
        Me.SuspendLayout()
        '
        'txtguess
        '
        Me.txtguess.Location = New System.Drawing.Point(105, 91)
        Me.txtguess.Name = "txtguess"
        Me.txtguess.Size = New System.Drawing.Size(75, 22)
        Me.txtguess.TabIndex = 0
        '
        'btnok
        '
        Me.btnok.Location = New System.Drawing.Point(12, 203)
        Me.btnok.Name = "btnok"
        Me.btnok.Size = New System.Drawing.Size(75, 23)
        Me.btnok.TabIndex = 3
        Me.btnok.Text = "確定"
        Me.btnok.UseVisualStyleBackColor = True
        '
        'btnreset
        '
        Me.btnreset.Location = New System.Drawing.Point(105, 203)
        Me.btnreset.Name = "btnreset"
        Me.btnreset.Size = New System.Drawing.Size(75, 23)
        Me.btnreset.TabIndex = 4
        Me.btnreset.Text = "重玩"
        Me.btnreset.UseVisualStyleBackColor = True
        '
        'btnexit
        '
        Me.btnexit.Location = New System.Drawing.Point(203, 203)
        Me.btnexit.Name = "btnexit"
        Me.btnexit.Size = New System.Drawing.Size(75, 23)
        Me.btnexit.TabIndex = 5
        Me.btnexit.Text = "離開"
        Me.btnexit.UseVisualStyleBackColor = True
        '
        'txttop
        '
        Me.txttop.FlatStyle = System.Windows.Forms.FlatStyle.System
        Me.txttop.Location = New System.Drawing.Point(52, 26)
        Me.txttop.Name = "txttop"
        Me.txttop.Size = New System.Drawing.Size(176, 38)
        Me.txttop.TabIndex = 6
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(88, 94)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(11, 12)
        Me.Label1.TabIndex = 7
        Me.Label1.Text = "<"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(184, 94)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(11, 12)
        Me.Label2.TabIndex = 8
        Me.Label2.Text = "<"
        '
        'txtsmall
        '
        Me.txtsmall.Location = New System.Drawing.Point(12, 91)
        Me.txtsmall.Name = "txtsmall"
        Me.txtsmall.Size = New System.Drawing.Size(75, 22)
        Me.txtsmall.TabIndex = 9
        '
        'txtlarge
        '
        Me.txtlarge.Location = New System.Drawing.Point(203, 91)
        Me.txtlarge.Name = "txtlarge"
        Me.txtlarge.Size = New System.Drawing.Size(75, 22)
        Me.txtlarge.TabIndex = 0
        '
        'done
        '
        Me.done.Location = New System.Drawing.Point(105, 160)
        Me.done.Name = "done"
        Me.done.Size = New System.Drawing.Size(75, 23)
        Me.done.TabIndex = 11
        Me.done.Text = "設定完成"
        Me.done.UseVisualStyleBackColor = True
        '
        'form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(284, 262)
        Me.Controls.Add(Me.done)
        Me.Controls.Add(Me.txtlarge)
        Me.Controls.Add(Me.txtsmall)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.txttop)
        Me.Controls.Add(Me.btnexit)
        Me.Controls.Add(Me.btnreset)
        Me.Controls.Add(Me.btnok)
        Me.Controls.Add(Me.txtguess)
        Me.Name = "form1"
        Me.Text = "終極密碼"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents txtguess As System.Windows.Forms.TextBox
    Friend WithEvents btnok As System.Windows.Forms.Button
    Friend WithEvents btnreset As System.Windows.Forms.Button
    Friend WithEvents btnexit As System.Windows.Forms.Button
    Friend WithEvents txttop As System.Windows.Forms.Label
    Friend WithEvents ToolTip1 As System.Windows.Forms.ToolTip
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents txtsmall As System.Windows.Forms.TextBox
    Friend WithEvents txtlarge As System.Windows.Forms.TextBox
    Friend WithEvents done As System.Windows.Forms.Button
    Friend WithEvents ToolTip2 As System.Windows.Forms.ToolTip
    Friend WithEvents ToolTip3 As System.Windows.Forms.ToolTip

End Class
