Public Class new_entry

    Dim dbConn As New ADODB.Connection

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Me.Close()
        clerk.Show()
    End Sub

    Private Sub CancelToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CancelToolStripMenuItem.Click
        Me.Close()
        clerk.Show()
    End Sub

    Private Sub new_entry_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Try
            dbConn.ConnectionString = "Driver={Microsoft ODBC for Oracle};" & "UID=System;PWD=sys"
            dbConn.Open()

            'total no of records
            Dim recordCount As Integer
            Dim objRS As New ADODB.Recordset
            With objRS
                .CursorLocation = ADODB.CursorLocationEnum.adUseServer
                .CursorType = ADODB.CursorTypeEnum.adOpenForwardOnly
                .LockType = ADODB.LockTypeEnum.adLockReadOnly
            End With
            objRS.Open("SELECT count(*) FROM p_details", dbConn)
            recordCount = objRS.Fields(0).Value
            objRS.Close()


            'id of last record
            Dim tmpInt As Integer
            objRS.Open("SELECT * FROM p_details", dbConn)
            tmpInt = objRS.Fields(0).Value
            While objRS.EOF = False
                If tmpInt < objRS.Fields(0).Value Then
                    tmpInt = objRS.Fields(0).Value
                End If
                objRS.MoveNext()
            End While

            Label24.Text = recordCount
            Label25.Text = tmpInt + 1

        Catch ex As Exception

        End Try
    End Sub

    Private Sub SaveChangesToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles SaveChangesToolStripMenuItem.Click
        saveEntry()
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        saveEntry()
    End Sub

    Private Sub saveEntry()
        Label22.Text = ""
        Dim recSec As New ADODB.Recordset
        Dim query As String

        Try
            'more conditions are to be added later...
            If Not TextBox1.Text = "" And Not ComboBox1.Text = "" And (RadioButton1.Checked Or RadioButton2.Checked) And Not ComboBox1.Text = "" And Not TextBox2.Text = "" _
            And Not TextBox3.Text = "" And Not TextBox4.Text = "" And Not TextBox5.Text = "" And Not TextBox6.Text = "" And Not TextBox7.Text = "" And Not TextBox8.Text = "" _
            And Not Convert.ToInt32(TextBox6.Text) < 0 And Not Convert.ToInt32(TextBox7.Text) < 0 And Not Convert.ToInt32(TextBox8.Text) < 0 Then

                query = "INSERT INTO p_details VALUES (" & Label25.Text & ",'" & TextBox1.Text & "',TO_DATE('" & NumericUpDown3.Value & "-" & NumericUpDown2.Value _
                & "-" & NumericUpDown1.Value & "','YYYY-MM-DD'),'" & ComboBox1.Text & "',"
                If RadioButton1.Enabled Then
                    query = query & "1,"
                ElseIf RadioButton2.Enabled Then
                    query = query & "2,"
                End If
                query = query & "'" & TextBox2.Text & "','" & TextBox3.Text & "','" & TextBox4.Text & "','" & TextBox5.Text & "'," _
                & TextBox6.Text & "," & TextBox7.Text & "," & TextBox8.Text & ")"

                recSec.Open(query, dbConn)

                Me.Close()
                clerk.Show()

                MsgBox("Entry saved", , "Success")

            Else
                Label22.Text = "Invalid field value(s)"
            End If

        Catch ex As Exception

        End Try

    End Sub

End Class